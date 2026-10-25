import unreal
import s_gm

def open_or_create_level(level_path):
    """Service: Carga un nivel existente o crea uno nuevo en la ruta dada."""
    subsystem = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)

    if unreal.EditorAssetLibrary.does_asset_exist(level_path):
        success = False
        if subsystem and hasattr(subsystem, "load_level"):
            try:
                success = subsystem.load_level(level_path)
            except Exception as e:
                unreal.log_warning(f"[Service:Level] Excepción en subsystem.load_level: {e}")
        elif hasattr(unreal.EditorLevelLibrary, "load_level"):
            try:
                success = unreal.EditorLevelLibrary.load_level(level_path)
            except Exception as e:
                unreal.log_warning(f"[Service:Level] Excepción en EditorLevelLibrary.load_level: {e}")
        else:
            unreal.log_error(f"[Service:Level] No se pudo encontrar método para cargar {level_path}")
        unreal.log(f"[Service:Level] Nivel cargado ('{level_path}'): {success}")
    else:
        success = False
        if subsystem and hasattr(subsystem, "new_level"):
            try:
                success = subsystem.new_level(level_path)
            except Exception as e:
                unreal.log_warning(f"[Service:Level] Excepción en subsystem.new_level: {e}")
        elif hasattr(unreal.EditorLevelLibrary, "new_level"):
            try:
                success = unreal.EditorLevelLibrary.new_level(level_path)
            except Exception as e:
                unreal.log_warning(f"[Service:Level] Excepción en EditorLevelLibrary.new_level: {e}")
        else:
            unreal.log_error(f"[Service:Level] No se pudo encontrar método para crear {level_path}")
        unreal.log(f"[Service:Level] Nuevo nivel creado ('{level_path}'): {success}")

def initialize_level(level_path, gamemode_path):
    """Service: Orquesta la inicialización de un nuevo nivel o carga uno existente con su GameMode."""
    open_or_create_level(level_path)
    s_gm.set_level_gamemode(level_path, gamemode_path)
    unreal.log("[Service:Level] Nivel inicializado: " + level_path)
