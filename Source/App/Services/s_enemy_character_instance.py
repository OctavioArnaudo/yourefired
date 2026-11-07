# ============================================================
# YOU'RE FIRED - Service : Enemy Character Instance
# ============================================================
import unreal
import s_patrol
import s_melee
import s_shoot
from m_shoot import MShootData

class SEnemyCharacterInstance:
    """Service: Lógica de comportamiento de instancia enemiga delegando a servicios unitarios."""

    def __init__(self):
        self.shoot_model = MShootData(speed=1000.0, fire_rate=0.5)

    def execute_patrol(self, enemy_actor, home_location=(0.0, 0.0, 0.0), radius=500.0):
        unreal.log("[Service:SEnemyCharacterInstance] Delegando patrullaje a servicio unitario s_patrol.")
        return s_patrol.execute_patrol_step(enemy_actor, home_location, radius)

    def perform_melee_attack(self, enemy_actor):
        unreal.log("[Service:SEnemyCharacterInstance] Delegando ataque cuerpo a cuerpo a s_melee.")
        return s_melee.perform_melee_attack(enemy_actor)

    def perform_ranged_attack(self, enemy_actor, projectile_class_path=None, current_time=0.0):
        unreal.log("[Service:SEnemyCharacterInstance] Delegando disparo discreto a distancia a s_shoot.")
        return s_shoot.perform_discrete_ranged_shoot(enemy_actor, self.shoot_model, projectile_class_path, current_time)
