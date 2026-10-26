# ============================================================
# YOU'RE FIRED - Controller: Coworker Enemy AI & Logic
# ============================================================
import unreal
import c_actor_spawner

def spawn_coworker_enemy(name="Coworker_01", position=(-800, 300, 75)):
    """Controller: Spawnea un compañero de trabajo hostil (enemigo) en la oficina."""
    unreal.log(f"[Controller:CoworkerEnemy] Spawning coworker enemy: {name}")
    return c_actor_spawner.spawn_actor(name, "/Script/App.CoworkerEnemy", position)

def on_coworker_alert(enemy_actor, player_actor):
    """Controller: Lógica de IA cuando el compañero detecta al jugador (aumenta estrés / persigue)."""
    if enemy_actor and enemy_actor.is_valid():
        unreal.log(f"[Controller:CoworkerEnemy] {enemy_actor.get_actor_label()} ha detectado al jugador. ¡Cuidado con el chisme corporativo!")
    return True
