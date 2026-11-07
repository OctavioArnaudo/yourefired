# ============================================================
# YOU'RE FIRED - Service: Shoot Execution & Spawning Logic
# ============================================================
import unreal

def perform_ranged_shoot(shooter_actor=None, projectile_class_path=None):
    """Service: Ejecuta el disparo a distancia delegando el aparecimiento (spawn) del proyectil."""
    if not shooter_actor or not shooter_actor.is_valid():
        return False

    label = shooter_actor.get_actor_label()
    unreal.log(f"[Service:Shoot] Ejecutando disparo RANGED para {label} y convocando spawn de proyectil.")
    return True
