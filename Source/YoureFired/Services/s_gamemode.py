import unreal

def set_level_gamemode(level_path, gm_class_path):
    """Service: Asigna un GameMode específico a un nivel mediante WorldSettings."""
    world = unreal.EditorLevelLibrary.get_editor_world()
    if not world:
        unreal.log_error("No se pudo obtener el mundo actual.")
        return

    gm_class = unreal.load_class(None, gm_class_path)
    if not gm_class:
        unreal.log_error("No se pudo cargar la clase GameMode: " + gm_class_path)
        return

    world_settings = world.get_world_settings()
    world_settings.set_editor_property("game_mode_override", gm_class)
    unreal.log("[Service:Gamemode] GameMode asignado: " + gm_class_path)
