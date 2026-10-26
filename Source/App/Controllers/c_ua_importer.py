# ============================================================
# YOU'RE FIRED - Controller: Asset Import Command
# ============================================================
import unreal
import s_ua_importer

def execute_raw_assets_import():
    """Controller: Comando para ejecutar la importación automática de archivos primarios .png y .fbx."""
    unreal.log("[Controller:UaImporter] Iniciando comando de importación de assets primarios .png y .fbx.")
    s_ua_importer.import_all_raw_assets()
