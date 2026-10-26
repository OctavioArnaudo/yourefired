# ============================================================
# YOU'RE FIRED - Service: Material Placeholder (M_, MI_)
# ============================================================
import unreal
import os

def ensure_m_placeholders():
    unreal.log("[Service:M_Placeholder] Verificando Materiales (M_, MI_)...")
    materials = [
        ("/Game/YoureFired/Materials/M_OfficeStyle.M_OfficeStyle", "/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"),
        ("/Game/YoureFired/Materials/M_UITheme.M_UITheme", "/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"),
        ("/Game/YoureFired/Materials/MI_OfficeVariant.MI_OfficeVariant", "/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial")
    ]
    content_dir = unreal.Paths.project_content_dir()
    for custom_path, source_base in materials:
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
                    unreal.log(f"[Service:M_Placeholder] Creado: {disk_path}")
            except Exception as e:
                unreal.log_error(f"[Service:M_Placeholder] Error en {custom_path}: {e}")
