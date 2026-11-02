# c_player_character_instance.py
# Script con depuración avanzada para revelar errores detallados en la consola de Unreal Engine.

import unreal
import traceback

def setup_player_inputs():
    """Configura los mapeos de input con manejo estricto de errores."""
    unreal.log("[CPlayerCharacterInstance] Iniciando configuración de inputs...")
    try:
        input_settings = unreal.InputSettings.get_default_object()
        if not input_settings:
            unreal.log_error("[CPlayerCharacterInstance] CRITICAL: InputSettings.get_default_object() devolvió None.")
            return

        def add_axis(axis_name, key_name, scale):
            mapping = unreal.InputAxisKeyMapping()
            mapping.axis_name = axis_name
            mapping.key = key_name
            mapping.scale = scale
            input_settings.add_axis_mapping(mapping)

        def add_action(action_name, key_name):
            mapping = unreal.InputActionKeyMapping()
            mapping.action_name = action_name
            mapping.key = key_name
            input_settings.add_action_mapping(mapping)

        axis_mappings = input_settings.get_editor_property('axis_mappings')

        if not any(m.axis_name == 'MoveForward' for m in axis_mappings):
            add_axis('MoveForward', 'W', 1.0)
            add_axis('MoveForward', 'S', -1.0)
            unreal.log("[CPlayerCharacterInstance] Mapeo de Eje 'MoveForward' añadido.")

        if not any(m.axis_name == 'MoveRight' for m in axis_mappings):
            add_axis('MoveRight', 'D', 1.0)
            add_axis('MoveRight', 'A', -1.0)
            unreal.log("[CPlayerCharacterInstance] Mapeo de Eje 'MoveRight' añadido.")

        action_mappings = input_settings.get_editor_property('action_mappings')

        if not any(m.action_name == 'Sprint' for m in action_mappings):
            add_action('Sprint', 'LeftShift')
            unreal.log("[CPlayerCharacterInstance] Acción 'Sprint' añadida.")

        if not any(m.action_name == 'MeleeAttack' for m in action_mappings):
            add_action('MeleeAttack', 'LeftMouseButton')
            unreal.log("[CPlayerCharacterInstance] Acción 'MeleeAttack' añadida.")

        if not any(m.action_name == 'RangedAttack' for m in action_mappings):
            add_action('RangedAttack', 'RightMouseButton')
            unreal.log("[CPlayerCharacterInstance] Acción 'RangedAttack' añadida.")

        input_settings.save_key_mappings()
        input_settings.post_edit_change()
        unreal.log("[CPlayerCharacterInstance] Mapeos de input guardados y actualizados correctamente.")

    except Exception as e:
        unreal.log_error(f"[CPlayerCharacterInstance] Error en setup_player_inputs: {str(e)}")
        unreal.log_error(traceback.format_exc())

def spawn_and_configure_player():
    """Spawnea el actor con validación exhaustiva de rutas, módulos y errores en consola."""
    unreal.log("[CPlayerCharacterInstance] Iniciando proceso de spawn del personaje...")

    try:
        # 1. Verificación del mundo activo
        unreal_editor_subsystem = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem)
        world = unreal_editor_subsystem.get_game_world()

        if not world and hasattr(unreal, "EditorLevelLibrary"):
            world = unreal.EditorLevelLibrary.get_editor_world()

        if not world:
            unreal.log_error("[CPlayerCharacterInstance] ERROR: No se pudo obtener el mundo activo del editor.")
            return

        unreal.log(f"[CPlayerCharacterInstance] Mundo detectado: {world.get_name()}")

        # 2. Carga de la clase C++ (Intenta múltiples nombres comunes de módulos si 'App' falla)
        possible_paths = [
            "/Script/App.CPlayerCharacterInstance",
            "/Script/MyGame.CPlayerCharacterInstance",
            "/Script/YourGame.CPlayerCharacterInstance"
        ]

        cls = None
        loaded_path = ""
        for path in possible_paths:
            unreal.log(f"[CPlayerCharacterInstance] Intentando cargar clase desde: {path}")
            cls = unreal.load_class(None, path)
            if cls:
                loaded_path = path
                unreal.log(f"[CPlayerCharacterInstance] ¡Clase cargada exitosamente desde: {loaded_path}!")
                break

        if not cls:
            unreal.log_error("[CPlayerCharacterInstance] ERROR CRÍTICO: No se pudo cargar CPlayerCharacterInstance con ninguna ruta de módulo conocida.")
            unreal.log_error("[CPlayerCharacterInstance] SUGERENCIA: Revisa el nombre del módulo en tu archivo .Build.cs de C++ (por ejemplo, 'App' o el nombre de tu proyecto).")
            return

        # 3. Spawn del actor
        location = unreal.Vector(0.0, 0.0, 200.0)
        rotation = unreal.Rotator(0.0, 0.0, 0.0)

        actor_subsystem = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
        if not actor_subsystem:
            unreal.log_error("[CPlayerCharacterInstance] ERROR: EditorActorSubsystem no disponible.")
            return

        spawned_actor = actor_subsystem.spawn_actor_from_class(cls, location, rotation)

        if not spawned_actor:
            unreal.log_error("[CPlayerCharacterInstance] ERROR: El subsistema no pudo spawnear el actor de la clase dada.")
            return

        unreal.log(f"[CPlayerCharacterInstance] Actor spawneado con éxito: {spawned_actor.get_name()} en la ubicación {location}")

        # 4. Configuración de propiedades con manejo de excepciones individuales
        try:
            spawned_actor.set_editor_property("auto_possess_player", unreal.AutoReceiveInput.PLAYER0)
            unreal.log("[CPlayerCharacterInstance] Propiedad 'auto_possess_player' configurada a PLAYER0.")
        except Exception as prop_err:
            unreal.log_warning(f"[CPlayerCharacterInstance] Advertencia al configurar propiedad de auto-posesión: {prop_err}")

        # 5. Posesión en caliente (si el juego está corriendo en PIE)
        pc = unreal.GameplayStatics.get_player_controller(world, 0)
        if pc:
            pc.possess(spawned_actor)
            pc.set_view_target(spawned_actor)
            unreal.log("[CPlayerCharacterInstance] ÉXITO: El PlayerController 0 ha poseído al actor y asignado la cámara.")
        else:
            unreal.log("[CPlayerCharacterInstance] Nota: Estás en modo edición estático (Output Log). El auto-possess funcionará al presionar Play (PIE).")

    except Exception as e:
        unreal.log_error(f"[CPlayerCharacterInstance] Excepción no controlada en spawn_and_configure_player: {str(e)}")
        unreal.log_error(traceback.format_exc())

def run_unit_test():
    unreal.log("==================================================")
    unreal.log("[CPlayerCharacterInstance] >>> INICIO DE PRUEBA DE UNIDAD PYTHON <<<")
    setup_player_inputs()
    spawn_and_configure_player()
    unreal.log("[CPlayerCharacterInstance] >>> FIN DE PRUEBA DE UNIDAD PYTHON <<<")
    unreal.log("==================================================")

if __name__ == "__main__":
    run_unit_test()
