# ============================================================
# YOU'RE FIRED - Controller: Paper2D Flipbook Controller
# ============================================================
import unreal

def play_flipbook_animation(actor, flipbook_name):
    """Controller: Asigna y reproduce un Paper2D Flipbook 2D en el componente visual del actor."""
    if not actor or not actor.is_valid():
        return False

    fb_path = f"/Game/YoureFired/Flipbooks/FB_{flipbook_name}.FB_{flipbook_name}"
    if unreal.EditorAssetLibrary.does_asset_exist(f"/Game/YoureFired/Flipbooks/FB_{flipbook_name}"):
        flipbook_asset = unreal.load_class(None, fb_path)
        if flipbook_asset and hasattr(actor, "render_component") and actor.render_component:
            actor.render_component.set_flipbook(flipbook_asset)
            unreal.log(f"[Controller:FB_Placeholder] Reproduciendo animación 2D FB_{flipbook_name} en {actor.get_actor_label()}.")
            return True
    return False
