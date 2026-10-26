# ============================================================
# YOU'RE FIRED - Controller: Unitary Player 2D Movement
# ============================================================
import unreal

def apply_2d_movement_input(player_character, input_vector_2d):
    """Controller: Aplica entrada vectorial 2D (X horizontal, Y profundidad) al componente de movimiento."""
    if not player_character or not player_character.is_valid():
        return False

    if not FMath_is_nearly_zero(input_vector_2d.x):
        player_character.add_movement_input(unreal.Vector.FORWARD, input_vector_2d.x)
    if not FMath_is_nearly_zero(input_vector_2d.y):
        player_character.add_movement_input(unreal.Vector.RIGHT, input_vector_2d.y)
    return True

def FMath_is_nearly_zero(val):
    return abs(val) < 0.001
