# ============================================================
# YOU'RE FIRED - Service: Unified PNG/JPG & FBX Asset Importer
# ============================================================
import unreal
import os
import m_raw_placeholder

def import_primary_asset(source_filepath, destination_package_path, asset_name=None):
    """Service: Importa un archivo primario .png, .jpg o .fbx directamente en su categoría correspondiente."""
    if not os.path.exists(source_filepath):
        return None

    if not asset_name:
        base = os.path.basename(source_filepath)
        raw_name = os.path.splitext(base)[0]
        ext = os.path.splitext(base)[1].lower()

        if ext in [".png", ".jpg"]:
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

    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
    asset_tools.import_asset_tasks([task])

    imported_paths = task.get_editor_property("imported_object_paths")
    if imported_paths and len(imported_paths) > 0:
        unreal.log(f"[Service:UaImporter] Importado: '{source_filepath}' -> '{imported_paths[0]}'.")
        return imported_paths[0]

    return None

def import_all_raw_assets():
    """Service: Escanea e importa automáticamente todos los archivos .png, .jpg y .fbx en Content/YoureFired/."""
    base_dir = m_raw_placeholder.CONTENT_DIR
    if not os.path.exists(base_dir):
        return

    for root, dirs, files in os.walk(base_dir):
        for file in files:
            ext = os.path.splitext(file)[1].lower()
            if ext in [".png", ".jpg", ".fbx"]:
                src_path = os.path.join(root, file)
                rel_dir = os.path.relpath(root, base_dir).replace("\\", "/")
                dest_package = f"/Game/YoureFired/{rel_dir}" if rel_dir != "." else "/Game/YoureFired"
                import_primary_asset(src_path, dest_package)
