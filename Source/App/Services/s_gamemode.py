import unreal

def set_level_gamemode(level_path, gm_class_path):
    """Service: Asigna un GameMode específico a un nivel mediante WorldSettings con fallback inteligente."""
    world = unreal.EditorLevelLibrary.get_editor_world()
    if not world:
        unreal.log_error("No se pudo obtener el mundo actual.")
        return

    gm_class = None
    if gm_class_path:
        asset_package = gm_class_path.split('.')[0]
        if unreal.EditorAssetLibrary.does_asset_exist(asset_package):
            gm_class = unreal.load_class(None, gm_class_path)

    if not gm_class:
        # Intentar cargar clase C++ o fallback a GameModeBase nativo de Unreal
        gm_class = unreal.load_class(None, "/Script/App.YoureFiredGM")
        if not gm_class:
            gm_class = getattr(unreal, "GameModeBase", None) or getattr(unreal, "GameMode", None)

    if gm_class:
        world_settings = world.get_world_settings()
        property_set = False
        # Probar propiedades válidas de AWorldSettings en UE 5
        for prop_name in ["default_game_mode", "default_game_mode_class", "game_mode_override"]:
            try:
                world_settings.set_editor_property(prop_name, gm_class)
                property_set = True
                unreal.log(f"[Service:Gamemode] GameMode asignado exitosamente usando '{prop_name}'.")
                break
            except Exception:
                continue

        if not property_set:
            unreal.log_error("[Service:Gamemode] No se pudo establecer la propiedad de GameMode en WorldSettings.")
    else:
        unreal.log_error("[Service:Gamemode] Error crítico: No se pudo resolver ningún GameMode válido.")
