# ============================================================
# YOU'RE FIRED - Service : Enemy Character Instance
# ============================================================
import sys
import os

_current_dir = os.path.dirname(os.path.abspath(__file__))
_app_dir = os.path.dirname(_current_dir) if os.path.basename(_current_dir) in ['Models', 'Controllers', 'Views', 'Services', 'Interfaces'] else _current_dir
for _folder in ['', 'Models', 'Controllers', 'Views', 'Services', 'Interfaces']:
    _path = os.path.join(_app_dir, _folder)
    if _path not in sys.path:
        sys.path.insert(0, _path)

import unreal
import s_patrol
import s_melee
import s_shoot
import s_health
from m_health import MHealthData
from c_health import CHealthController
from m_shoot import MShootData

class SEnemyCharacterInstance:
    """Service: Lógica de comportamiento de instancia enemiga delegando a servicios unitarios (incluyendo Health)."""

    def __init__(self, max_health=80.0):
        self.shoot_model = MShootData(speed=1000.0, fire_rate=1.5) # Cadencia equilibrada 1.5s
        self.health_model = MHealthData(max_health=max_health)
        self.health_controller = CHealthController()
        self.health_service = s_health.SHealthService()

    def get_health(self):
        return self.health_controller.get_health(self.health_model)

    def get_max_health(self):
        return self.health_controller.get_max_health(self.health_model)

    def is_dead(self):
        return self.health_controller.is_dead(self.health_model)

    def take_damage(self, target_actor, amount):
        unreal.log(f"[SEnemyCharacterInstance] Enemigo recibiendo {amount} de daño.")
        return self.health_service.apply_damage_to_actor(target_actor, self.health_model, amount)

    def heal(self, target_actor, amount):
        unreal.log(f"[SEnemyCharacterInstance] Enemigo recuperando {amount} de vida.")
        return self.health_service.apply_healing_to_actor(target_actor, self.health_model, amount)

    def execute_patrol(self, enemy_actor, home_location=(0.0, 0.0, 0.0), radius=500.0):
        if self.is_dead():
            return False
        return s_patrol.execute_patrol_step(enemy_actor, home_location, radius)

    def perform_melee_attack(self, enemy_actor):
        if self.is_dead():
            return False
        return s_melee.perform_melee_attack(enemy_actor)

    def perform_ranged_attack(self, enemy_actor, projectile_class_path=None, current_time=0.0):
        if self.is_dead():
            return False
        if enemy_actor and enemy_actor.is_valid():
            world = enemy_actor.get_world()
            if world:
                current_time = world.get_time_seconds()
        return s_shoot.perform_discrete_ranged_shoot(enemy_actor, self.shoot_model, projectile_class_path, current_time)
