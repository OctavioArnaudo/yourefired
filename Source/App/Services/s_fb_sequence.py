# ============================================================
# YOU'RE FIRED - Service: Unitary PNG Sequence Scanner & Sorter
# ============================================================
import unreal

def scan_and_sort_png_textures(sequence_folder_path):
    """Service: Escanea y ordena secuencialmente las texturas .png de una carpeta."""
    textures = []
    if unreal.EditorAssetLibrary.does_directory_exist(sequence_folder_path):
        assets = unreal.EditorAssetLibrary.list_assets(sequence_folder_path, recursive=False)
        for asset_path in assets:
            loaded_asset = unreal.EditorAssetLibrary.load_asset(asset_path)
            if loaded_asset and isinstance(loaded_asset, unreal.Texture2D):
                textures.append(loaded_asset)

    textures.sort(key=lambda t: t.get_name())
    unreal.log(f"[Service:FbSequence] Encontradas {len(textures)} texturas en '{sequence_folder_path}'.")
    return textures
