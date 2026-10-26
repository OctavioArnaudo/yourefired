# ============================================================
# YOU'RE FIRED - Service: Unitary PaperSprite Generator
# ============================================================
import unreal

def create_sprites_from_textures(textures, destination_sprite_dir):
    """Service: Convierte una lista de texturas Texture2D en assets PaperSprite (SPR_)."""
    sprites = []
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

    if not unreal.EditorAssetLibrary.does_directory_exist(destination_sprite_dir):
        unreal.EditorAssetLibrary.make_directory(destination_sprite_dir)

    for tex in textures:
        sprite_name = f"SPR_{tex.get_name()}"
        sprite_path = f"{destination_sprite_dir}/{sprite_name}"

        if unreal.EditorAssetLibrary.does_asset_exist(sprite_path):
            sprite_asset = unreal.EditorAssetLibrary.load_asset(sprite_path)
        else:
            try:
                factory = getattr(unreal, "PaperSpriteFactory", None)
                if factory:
                    sprite_asset = asset_tools.create_asset(sprite_name, destination_sprite_dir, unreal.PaperSprite, factory())
                    if sprite_asset:
                        sprite_asset.set_editor_property("source_texture", tex)
                        unreal.EditorAssetLibrary.save_loaded_asset(sprite_asset)
                else:
                    sprite_asset = None
            except Exception:
                sprite_asset = None

        if sprite_asset:
            sprites.append(sprite_asset)

    return sprites
