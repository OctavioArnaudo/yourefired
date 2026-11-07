# ============================================================
# YOU'RE FIRED - Controller : Camera Controller
# ============================================================
import unreal

class CCameraController:
    """Controller: Gestion de entradas de zoom y rotacion de camara."""

    def update_camera_zoom(self, camera_component, zoom_delta):
        if not camera_component:
            return False
        unreal.log(f"[CCameraController] Zoom de camara actualizado por delta: {zoom_delta}")
        return True
