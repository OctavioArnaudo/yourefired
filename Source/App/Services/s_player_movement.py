# ============================================================
# YOU'RE FIRED - Service: Unitary Movement Plane Constraints
# ============================================================
import unreal

def configure_2d_movement_component(character_movement, max_speed=300.0):
    """Service: Configura restricciones de plano 2D XY en el CharacterMovementComponent."""
    if not character_movement:
        return False
    try:
        character_movement.set_editor_property("max_walk_speed", max_speed)
        character_movement.set_editor_property("constrain_to_plane", True)
        character_movement.set_editor_property("plane_constraint_normal", unreal.Vector(0.0, 0.0, 1.0))
        character_movement.set_editor_property("snap_to_plane_at_start", True)
        character_movement.set_editor_property("b_orient_rotation_to_movement", False)
        return True
    except Exception:
        return False
