# ============================================================
# YOU'RE FIRED - Service: Widget Blueprint Placeholder (WBP_)
# ============================================================
import unreal
import os

def ensure_wbp_placeholders():
    unreal.log("[Service:WBP_Placeholder] Verificando Widget Blueprints (WBP_)...")
    widgets = [
        "/Game/YoureFired/UI/WBP_MainMenu",
        "/Game/YoureFired/UI/WBP_HUD",
        "/Game/YoureFired/UI/WBP_Victory",
        "/Game/YoureFired/UI/WBP_Defeat",
        "/Game/YoureFired/UI/WBP_Settings"
    ]
    content_dir = unreal.Paths.project_content_dir()
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

    for widget_path in widgets:
        relative_path = widget_path.replace("/Game/", "") + ".uasset"
        disk_path = os.path.join(content_dir, relative_path)
        if not os.path.exists(disk_path):
            package_path = widget_path.rsplit("/", 1)[0]
            asset_name = widget_path.rsplit("/", 1)[1]
            if not unreal.EditorAssetLibrary.does_directory_exist(package_path):
                unreal.EditorAssetLibrary.make_directory(package_path)
            try:
                factory = unreal.WidgetBlueprintFactory()
                new_widget = asset_tools.create_asset(asset_name, package_path, unreal.WidgetBlueprint, factory)
                if new_widget:
                    unreal.EditorAssetLibrary.save_loaded_asset(new_widget)
                    unreal.log(f"[Service:WBP_Placeholder] Creado Widget: {disk_path}")
            except Exception as e:
                unreal.log_error(f"[Service:WBP_Placeholder] Error creando {widget_path}: {e}")
