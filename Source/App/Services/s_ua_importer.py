# ============================================================
# YOU'RE FIRED - Service: Primary PNG & FBX Asset Importer
# ============================================================
import unreal
import os
import m_ua_importer

def import_primary_asset(source_filepath, destination_package_path, asset_name=None):
    """Service: Importa un archivo primario .png o .fbx y lo convierte físicamente en un asset .uasset de Unreal Engine."""
    if not os.path.exists(source_filepath):
        unreal.log_warning(f"[Service:UaImporter] Archivo fuente no encontrado: {source_filepath}")
        return None

    if not asset_name:
        base = os.path.basename(source_filepath)
        raw_name = os.path.splitext(base)[0]
        ext = os.path.splitext(base)[1].lower()

        # Aplicar prefijos estrictos según la extensión (.png -> T_, .fbx -> SM_)
        if ext == ".png":
            asset_name = f"T_{raw_name}" if not raw_name.startswith("T_") else raw_name
        elif ext == ".fbx":
            asset_name = f"SM_{raw_name}" if not raw_name.startswith(("SM_", "SK_")) else raw_name
        else:
            asset_name = raw_name

    task = unreal.AssetImportTask()
    task.set_editor_property("filename", source_filepath)
    task.set_editor_property("destination_path", destination_package_path)
    task.set_editor_property("destination_name", asset_name)
    task.set_editor_property("automated", True)
    task.set_editor_property("save", True)
    task.set_editor_property("replace_existing", True)

    # Opciones de importación específicas para FBX
    if source_filepath.lower().endswith(".fbx"):
        options = unreal.FbxImportUI()
        options.set_editor_property("import_mesh", True)
        options.set_editor_property("import_textures", True)
        options.set_editor_property("import_materials", True)
        task.set_editor_property("options", options)

    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
    asset_tools.import_asset_tasks([task])

    imported_paths = task.get_editor_property("imported_object_paths")
    if imported_paths and len(imported_paths) > 0:
        unreal.log(f"[Service:UaImporter] ¡Asset importado exitosamente desde '{source_filepath}' -> '{imported_paths[0]}'.")
        return imported_paths[0]

    return None

def import_all_raw_assets():
    """Service: Escanea y convierte automáticamente todos los archivos primarios .png y .fbx en disco a .uasset."""
    unreal.log("[Service:UaImporter] Escaneando e importando archivos primarios .png y .fbx...")

    raw_dir = m_ua_importer.RAW_ASSETS_DIR
    if not os.path.exists(raw_dir):
        os.makedirs(raw_dir, exist_ok=True)
        unreal.log(f"[Service:UaImporter] Creada carpeta de assets primarios en: {raw_dir}")
        return

    for root, dirs, files in os.walk(raw_dir):
        for file in files:
            ext = os.path.splitext(file)[1].lower()
            if ext in [".png", ".fbx"]:
                src_path = os.path.join(root, file)
                dest_path = "/Game/YoureFired/Textures" if ext == ".png" else "/Game/YoureFired/Meshes"
                import_primary_asset(src_path, dest_path)
