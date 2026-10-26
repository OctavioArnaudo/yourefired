# ============================================================
# YOU'RE FIRED - Service: Static Mesh Placeholder (SM_)
# ============================================================
import unreal
import os
import m_sm_placeholder

def ensure_sm_placeholders():
    unreal.log("[Service:SM_Placeholder] Verificando Static Meshes (SM_)...")
    content_dir = unreal.Paths.project_content_dir()
    for custom_path, source_base in m_sm_placeholder.SM_PLACEHOLDERS:
        relative_path = custom_path.replace("/Game/", "").split(".")[0] + ".uasset"
        disk_path = os.path.join(content_dir, relative_path)
        if not os.path.exists(disk_path):
            parts = custom_path.split(".")
            object_path = parts[0]
            package_path = object_path.rsplit("/", 1)[0]
            if not unreal.EditorAssetLibrary.does_directory_exist(package_path):
                unreal.EditorAssetLibrary.make_directory(package_path)
            try:
                success = unreal.EditorAssetLibrary.duplicate_asset(source_base, object_path)
                if success:
                    asset = unreal.EditorAssetLibrary.load_asset(custom_path)
                    if asset:
                        unreal.EditorAssetLibrary.save_loaded_asset(asset)
                    unreal.log(f"[Service:SM_Placeholder] Creado: {disk_path}")
            except Exception as e:
                unreal.log_error(f"[Service:SM_Placeholder] Error en {custom_path}: {e}")
