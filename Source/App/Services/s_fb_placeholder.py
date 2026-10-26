# ============================================================
# YOU'RE FIRED - Service: Paper2D Flipbook Placeholder Orchestrator
# ============================================================
import unreal
import os
import s_fb_builder

FLIPBOOK_DEFINITIONS = [
    ("/Game/YoureFired/Flipbooks/FB_Player_Idle", 12.0),
    ("/Game/YoureFired/Flipbooks/FB_Player_Walk", 15.0),
    ("/Game/YoureFired/Flipbooks/FB_Coworker_Patrol", 10.0),
    ("/Game/YoureFired/Flipbooks/FB_Supervisor_Search", 10.0),
    ("/Game/YoureFired/Flipbooks/FB_Coffee_Spin", 20.0),
    ("/Game/YoureFired/Flipbooks/FB_Signature_Glow", 15.0)
]

def ensure_fb_placeholders():
    """Service: Orquestador ligero de Flipbooks 2D que delega en s_fb_builder."""
    unreal.log("[Service:FB_Placeholder] Verificando e importando secuencias PNG para Paper2D Flipbooks (FB_)...")

    # 1. Delegar construcción dinámica desde PNG a s_fb_builder
    s_fb_builder.build_flipbook_from_png_sequence("/Game/YoureFired/Textures/Player_Idle", "/Game/YoureFired/Flipbooks", "FB_Player_Idle", 12.0)
    s_fb_builder.build_flipbook_from_png_sequence("/Game/YoureFired/Textures/Player_Walk", "/Game/YoureFired/Flipbooks", "FB_Player_Walk", 15.0)

    # 2. Generar plantillas base .uasset si no hay secuencias .png presentes aún
    content_dir = unreal.Paths.project_content_dir()
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

    for fb_path, frames_per_sec in FLIPBOOK_DEFINITIONS:
        relative_path = fb_path.replace("/Game/", "") + ".uasset"
        disk_path = os.path.join(content_dir, relative_path)

        if not os.path.exists(disk_path):
            package_path = fb_path.rsplit("/", 1)[0]
            asset_name = fb_path.rsplit("/", 1)[1]

            if not unreal.EditorAssetLibrary.does_directory_exist(package_path):
                unreal.EditorAssetLibrary.make_directory(package_path)

            try:
                factory_cls = getattr(unreal, "PaperFlipbookFactory", None)
                if factory_cls:
                    new_fb = asset_tools.create_asset(asset_name, package_path, unreal.PaperFlipbook, factory_cls())
                    if new_fb:
                        unreal.EditorAssetLibrary.save_loaded_asset(new_fb)
                        unreal.log(f"[Service:FB_Placeholder] Creado Paper2D Flipbook: {disk_path}")
            except Exception as e:
                unreal.log_warning(f"[Service:FB_Placeholder] Nota en {fb_path}: {e}")
