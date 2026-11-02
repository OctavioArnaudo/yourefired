# ============================================================
# YOU'RE FIRED - Service: Player Character Instance Management
# ============================================================
import unreal

def validate_character_instance(instance_actor):
    """Service: Valida la integridad física y lógica de la instancia del jugador."""
    if instance_actor and instance_actor.is_valid():
        unreal.log(f"[Service:PlayerCharacterInstance] Instancia '{instance_actor.get_actor_label()}' validada con éxito.")
        return True
    return False
