import unreal

def get_asset_with_fallback(custom_path, default_path):
    """Service: Responsable exclusivo de cargar el asset personalizado o el default como fallback."""
    if unreal.EditorAssetLibrary.does_asset_exist(custom_path):
        loaded_asset = unreal.EditorAssetLibrary.load_asset(custom_path)
        if loaded_asset:
            return loaded_asset
    return unreal.EditorAssetLibrary.load_asset(default_path)
