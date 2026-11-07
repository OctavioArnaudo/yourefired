# ============================================================
# YOU'RE FIRED - View : Sprint FOV & Motion Blur Effects
# ============================================================
import unreal

class VSprintView:
    """View: Efecto visual de velocidad de camara al esprintar."""

    def apply_sprint_fov(self, camera_actor, b_enable):
        unreal.log(f"[VSprintView] FOV de camara de sprint cambiado: {b_enable}")
        return True
