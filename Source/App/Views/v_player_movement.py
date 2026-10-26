# ============================================================
# YOU'RE FIRED - View: Unitary Movement Vector Visualization
# ============================================================
import unreal

def render_movement_vector_debug(player_actor, velocity_vector):
    """View: Muestra el vector de velocidad 2D del jugador en pantalla para depuración."""
    unreal.log(f"[View:PlayerMovement] Vector de movimiento 2D: {velocity_vector}")
