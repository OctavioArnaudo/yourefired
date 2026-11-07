# ============================================================
# YOU'RE FIRED - Controller : Movement Input Dispatcher
# ============================================================
import unreal

class CMovementController:
    """Controller: Procesador de entradas de eje de movimiento."""

    def handle_axis_input(self, movement_model, axis_value, b_forward=True):
        if not movement_model:
            return False
        unreal.log(f"[CMovementController] Procesando eje {'Adelante' if b_forward else 'Derecha'}: {axis_value}")
        return True
