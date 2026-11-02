# ============================================================
# YOU'RE FIRED - View: Player Character Instance Render View
# ============================================================
import unreal

def render_character_instance_view(instance_actor):
    """View: Muestra el estado visual de la instancia del personaje en la escena."""
    if instance_actor and instance_actor.is_valid():
        unreal.log(f"[View:PlayerCharacterInstance] Renderizando instancia activa: {instance_actor.get_actor_label()}")
