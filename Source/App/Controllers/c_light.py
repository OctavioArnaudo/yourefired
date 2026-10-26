# ============================================================
# YOU'RE FIRED - Controller: Real-Time Lighting Setup
# ============================================================
import unreal

def get_actor_by_label(label):
    for actor in unreal.EditorLevelLibrary.get_all_level_actors():
        if actor and actor.get_actor_label() == label:
            return actor
    return None

def setup_directional_light(label, location, rotation, intensity=10.0):
    """Controller: Configura DirectionalLight con movilidad Movable para iluminación en tiempo real."""
    light = get_actor_by_label(label)
    if not light:
        light = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.DirectionalLight, unreal.Vector(*location), unreal.Rotator(*rotation))
        if light:
            light.set_actor_label(label)
    else:
        light.set_actor_location_and_rotation(unreal.Vector(*location), unreal.Rotator(*rotation), False, True)

    if light:
        if hasattr(light, "root_component") and light.root_component:
            light.root_component.set_editor_property("mobility", unreal.ComponentMobility.MOVABLE)
        light.light_component.set_editor_property("intensity", intensity)
    return light

def setup_sky_light(label, location=(0,0,500), intensity=2.0):
    """Controller: Configura SkyLight ambiental con movilidad Movable."""
    light = get_actor_by_label(label)
    if not light:
        light = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.SkyLight, unreal.Vector(*location), unreal.Rotator(0,0,0))
        if light:
            light.set_actor_label(label)
    else:
        light.set_actor_location_and_rotation(unreal.Vector(*location), unreal.Rotator(0,0,0), False, True)

    if light:
        if hasattr(light, "root_component") and light.root_component:
            light.root_component.set_editor_property("mobility", unreal.ComponentMobility.MOVABLE)
        light.light_component.set_editor_property("intensity", intensity)
    return light
