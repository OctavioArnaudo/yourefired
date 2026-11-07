# ============================================================
# YOU'RE FIRED - Service: Shoot Execution & Discrete Spawning Logic
# ============================================================
import unreal

def perform_ranged_shoot(shooter_actor=None, projectile_class_path=None):
    """Service: Ejecuta el disparo a distancia simple."""
    if not shooter_actor or not shooter_actor.is_valid():
        return False

    label = shooter_actor.get_actor_label()
    unreal.log(f"[Service:Shoot] Ejecutando disparo RANGED para {label} y convocando spawn de proyectil.")
    return True

def perform_discrete_ranged_shoot(shooter_actor, shoot_model, projectile_class_path=None, current_time=0.0):
    """Service: Ejecuta disparo discreto 1 a 1 controlando la cadencia (cooldown) cuando se mantiene presionado."""
    if not shooter_actor or not shooter_actor.is_valid() or not shoot_model:
        return False

    if not shoot_model.can_fire(current_time):
        return False  # Aun en enfriamiento; no dispara

    shoot_model.record_shot(current_time)
    label = shooter_actor.get_actor_label()
    unreal.log(f"[Service:Shoot] DISPARO DISCRETO 1-a-1 ejecutado para {label} en t={current_time:.2f}s (cadencia={shoot_model.fire_rate}s).")
    return True
