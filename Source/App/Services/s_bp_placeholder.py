# ============================================================
# YOU'RE FIRED - Service: Blueprint Placeholder (BP_)
# ============================================================
import unreal
import os

def ensure_bp_placeholders():
    unreal.log("[Service:BP_Placeholder] Verificando Blueprints (BP_)...")
    blueprints = [
        "/Game/YoureFired/Blueprints/BP_Player",
        "/Game/YoureFired/Blueprints/BP_CoworkerEnemy",
        "/Game/YoureFired/Blueprints/BP_SupervisorEnemy",
        "/Game/YoureFired/Blueprints/BP_CoffeeItem",
        "/Game/YoureFired/Blueprints/BP_SignatureItem",
        "/Game/YoureFired/Blueprints/BP_OfficeDoor"
    ]
    content_dir = unreal.Paths.project_content_dir()
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

    for bp_path in blueprints:
        relative_path = bp_path.replace("/Game/", "") + ".uasset"
        disk_path = os.path.join(content_dir, relative_path)
        if not os.path.exists(disk_path):
            package_path = bp_path.rsplit("/", 1)[0]
            asset_name = bp_path.rsplit("/", 1)[1]
            if not unreal.EditorAssetLibrary.does_directory_exist(package_path):
                unreal.EditorAssetLibrary.make_directory(package_path)
            try:
                factory = unreal.BlueprintFactory()
                factory.set_editor_property("parent_class", unreal.Character if "Player" in asset_name or "Enemy" in asset_name else unreal.Actor)
                new_bp = asset_tools.create_asset(asset_name, package_path, unreal.Blueprint, factory)
                if new_bp:
                    unreal.EditorAssetLibrary.save_loaded_asset(new_bp)
                    unreal.log(f"[Service:BP_Placeholder] Creado Blueprint: {disk_path}")
            except Exception as e:
                unreal.log_error(f"[Service:BP_Placeholder] Error creando {bp_path}: {e}")
