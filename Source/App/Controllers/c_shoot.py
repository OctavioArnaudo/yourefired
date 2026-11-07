# ============================================================
# YOU'RE FIRED - Controller: Shoot & Projectile Control
# ============================================================
import unreal

class CShootController:
    """Controller: Gestiona el estado de gatillo presionado/soltado."""

    def start_firing(self, shoot_model):
        if shoot_model:
            shoot_model.b_is_firing = True
            unreal.log("[CShootController] Gatillo presionado (b_is_firing = True).")
            return True
        return False

    def stop_firing(self, shoot_model):
        if shoot_model:
            shoot_model.b_is_firing = False
            unreal.log("[CShootController] Gatillo soltado (b_is_firing = False).")
            return True
        return False

def configure_shoot_behavior():
    """Controller: Configura y orquesta el disparo a distancia."""
    unreal.log("[CShoot] Configurando comportamiento de disparo...")

if __name__ == "__main__":
    configure_shoot_behavior()
