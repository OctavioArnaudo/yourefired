# ============================================================
# YOU'RE FIRED - Interface : Camera
# ============================================================
import unreal

class ICameraInterface:
    """Interface: Contrato formal de interacción para Camera."""
    def execute_camera_contract(self, data):
        raise NotImplementedError("execute_camera_contract debe ser implementado")
