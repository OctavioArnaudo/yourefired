# ============================================================
# YOU'RE FIRED - Interface: Paper2D Flipbook Contract
# ============================================================
import unreal

class IFBPlaceholderInterface:
    """Interface: Contrato para proveedores de animaciones Paper2D Flipbook 2D."""
    def play_animation(self, actor, animation_name):
        raise NotImplementedError("play_animation debe ser implementado")
