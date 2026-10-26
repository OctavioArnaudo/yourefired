# ============================================================
# YOU'RE FIRED - Service: Blueprint Placeholder (BP_)
# ============================================================
import unreal
import os

BLUEPRINT_DEFINITIONS = [
    ("/Game/YoureFired/Blueprints/BP_Player", unreal.Character, "/Script/App.PlayerCharacter"),
    ("/Game/YoureFired/Blueprints/BP_CoworkerEnemy", unreal.Character, "/Script/App.CoworkerEnemy"),
    ("/Game/YoureFired/Blueprints/BP_SupervisorEnemy", unreal.Character, "/Script/App.SupervisorEnemy"),
    ("/Game/YoureFired/Blueprints/BP_CoffeeItem", unreal.Actor, "/Script/App.CoffeePickup"),
    ("/Game/YoureFired/Blueprints/BP_SignatureItem", unreal.Actor, "/Script/App.SignaturePickup"),
    ("/Game/YoureFired/Blueprints/BP_OfficeDoor", unreal.Actor, "/Script/App.OfficeDoor"),
    ("/Game/YoureFired/Blueprints/BP_WeaponBase", unreal.Actor, "/Script/App.Weapon")
]

def ensure_bp_placeholders():
    """Service: Garantiza la existencia física de todos los Blueprints lógicos del juego con clases padre apropiadas."""
    unreal.log("[Service:BP_Placeholder] Verificando Blueprints lógicos (BP_)...")
    content_dir = unreal.Paths.project_content_dir()
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

    for bp_path, default_parent, cpp_class_path in BLUEPRINT_DEFINITIONS:
        relative_path = bp_path.replace("/Game/", "") + ".uasset"
        disk_path = os.path.join(content_dir, relative_path)

        if not os.path.exists(disk_path):
            package_path = bp_path.rsplit("/", 1)[0]
            asset_name = bp_path.rsplit("/", 1)[1]

            if not unreal.EditorAssetLibrary.does_directory_exist(package_path):
                unreal.EditorAssetLibrary.make_directory(package_path)

            try:
                parent_class = default_parent
                if cpp_class_path:
                    cpp_class = unreal.load_class(None, cpp_class_path)
                    if cpp_class:
                        parent_class = cpp_class

                factory = unreal.BlueprintFactory()
                factory.set_editor_property("parent_class", parent_class)

                new_bp = asset_tools.create_asset(asset_name, package_path, unreal.Blueprint, factory)
                if new_bp:
                    unreal.EditorAssetLibrary.save_loaded_asset(new_bp)
                    unreal.log(f"[Service:BP_Placeholder] Creado Blueprint '{asset_name}' en: {disk_path}")
            except Exception as e:
                unreal.log_error(f"[Service:BP_Placeholder] Error creando Blueprint '{bp_path}': {e}")
