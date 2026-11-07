# ============================================================
# YOU'RE FIRED - Service : Enemy Character Instance
# ============================================================
import unreal
import s_patrol
import s_melee
import s_shoot

class SEnemyCharacterInstance:
    """Service: Lógica de comportamiento de instancia enemiga delegando a servicios unitarios."""

    def execute_patrol(self, enemy_actor, home_location=(0.0, 0.0, 0.0), radius=500.0):
        unreal.log("[Service:SEnemyCharacterInstance] Delegando patrullaje a servicio unitario s_patrol.")
        return s_patrol.execute_patrol_step(enemy_actor, home_location, radius)

    def perform_melee_attack(self, enemy_actor):
        unreal.log("[Service:SEnemyCharacterInstance] Delegando ataque cuerpo a cuerpo a s_melee.")
        return s_melee.perform_melee_attack(enemy_actor)

    def perform_ranged_attack(self, enemy_actor, projectile_class_path=None):
        unreal.log("[Service:SEnemyCharacterInstance] Delegando disparo a distancia a s_shoot (invoca spawn).")
        return s_shoot.perform_ranged_shoot(enemy_actor, projectile_class_path)
