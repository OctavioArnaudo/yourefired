# ============================================================
# YOU'RE FIRED - Service: Unitary PaperFlipbook Asset Creator
# ============================================================
import unreal
import s_fb_sequence
import s_fb_sprite
import s_fb_keyframe

def build_flipbook_from_png_sequence(sequence_folder_path, flipbook_package_path, flipbook_name, fps=15.0):
    """Service: Ensambla el asset .uasset de PaperFlipbook delegando en s_fb_sequence, s_fb_sprite y s_fb_keyframe."""
    # 1. Delegar escaneo
    textures = s_fb_sequence.scan_and_sort_png_textures(sequence_folder_path)
    if not textures:
        return None

    # 2. Delegar generación de sprites
    sprite_dir = f"{flipbook_package_path}/Sprites"
    sprites = s_fb_sprite.create_sprites_from_textures(textures, sprite_dir)
    if not sprites:
        return None

    # 3. Delegar ensamblaje de keyframes
    keyframes = s_fb_keyframe.build_flipbook_keyframes(sprites)

    # 4. Crear/Guardar PaperFlipbook
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
    fb_path = f"{flipbook_package_path}/{flipbook_name}"

    if unreal.EditorAssetLibrary.does_asset_exist(fb_path):
        flipbook_asset = unreal.EditorAssetLibrary.load_asset(fb_path)
    else:
        factory = getattr(unreal, "PaperFlipbookFactory", None)
        flipbook_asset = asset_tools.create_asset(flipbook_name, flipbook_package_path, unreal.PaperFlipbook, factory()) if factory else None

    if flipbook_asset:
        try:
            flipbook_asset.set_editor_property("frames_per_second", fps)
            flipbook_asset.set_editor_property("keyframes", keyframes)
            unreal.EditorAssetLibrary.save_loaded_asset(flipbook_asset)
            unreal.log(f"[Service:FbBuilder] Flipbook '{flipbook_name}' ensamblado ({len(keyframes)} fotogramas).")
            return flipbook_asset
        except Exception as e:
            unreal.log_error(f"[Service:FbBuilder] Error en '{flipbook_name}': {e}")

    return None
