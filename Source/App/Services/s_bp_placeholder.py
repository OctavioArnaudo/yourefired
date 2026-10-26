# ============================================================
# YOU'RE FIRED - Service: Paper2D BP_Player & Blueprint Generator
# ============================================================
import unreal
import os
import m_bp_placeholder

def setup_bp_player_components(bp):
    """Service: Configura las propiedades de movimiento 2D y cámara en BP_Player de forma segura."""
    if not bp:
        return

    # 1. Intentar acceder al SCS si está expuesto en la API
    try:
        scs = getattr(bp, "simple_construction_script", None)
        if scs and hasattr(scs, "get_root_script_node"):
            root = scs.get_root_script_node()
            if root:
                # Nodo visual Flipbook
                if hasattr(unreal, "PaperFlipbookComponent"):
                    visual_node = scs.create_node(unreal.PaperFlipbookComponent, "Visual")
                    if visual_node:
                        scs.add_node(visual_node)
                        visual_node.set_editor_property("parent", root)

                # Nodo Cámara
                camera_node = scs.create_node(unreal.CameraComponent, "TopDownCamera")
                if camera_node:
                    scs.add_node(camera_node)
                    camera_node.set_editor_property("parent", root)
    except Exception as e:
        unreal.log_warning(f"[Service:BP_Placeholder] Nota en SCS BP_Player: {e}")

    # 2. Configuración de movimiento 2D XY en el CDO de la clase generada
    try:
        generated_class = bp.generated_class()
        if generated_class:
            cdo = unreal.get_default_object(generated_class)
            if hasattr(cdo, "get_editor_property"):
                movement = cdo.get_editor_property("character_movement")
                if movement:
                    try:
                        movement.set_editor_property("max_walk_speed", m_bp_placeholder.WALK_SPEED)
                        movement.set_editor_property("constrain_to_plane", True)
                        movement.set_editor_property("plane_constraint_normal", unreal.Vector(0.0, 0.0, 1.0))
                        movement.set_editor_property("snap_to_plane_at_start", True)
                        movement.set_editor_property("b_orient_rotation_to_movement", False)
                    except Exception:
                        pass

                try:
                    cdo.set_editor_property("use_controller_rotation_yaw", False)
                except Exception:
                    pass
    except Exception as e:
        unreal.log_warning(f"[Service:BP_Placeholder] Nota en CDO BP_Player: {e}")

def ensure_bp_placeholders():
    """Service: Garantiza la existencia física de BP_Player y Blueprints del juego configurados para 2D XY."""
    unreal.log("[Service:BP_Placeholder] Verificando y configurando BP_Player y Blueprints 2D (BP_)...")
    content_dir = unreal.Paths.project_content_dir()
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

    blueprints = [
        ("/Game/YoureFired/Blueprints/BP_Player", unreal.Character, "/Script/App.CPlayerCharacter"),
        ("/Game/YoureFired/Blueprints/BP_CoworkerEnemy", unreal.Character, "/Script/App.CCoworkerEnemy"),
        ("/Game/YoureFired/Blueprints/BP_SupervisorEnemy", unreal.Character, "/Script/App.CSupervisorEnemy"),
        ("/Game/YoureFired/Blueprints/BP_CoffeeItem", unreal.Actor, "/Script/App.CCoffeePickup"),
        ("/Game/YoureFired/Blueprints/BP_SignatureItem", unreal.Actor, "/Script/App.CSignaturePickup"),
        ("/Game/YoureFired/Blueprints/BP_OfficeDoor", unreal.Actor, "/Script/App.CDoor")
    ]

    for bp_path, default_parent, cpp_class_path in blueprints:
        relative_path = bp_path.replace("/Game/", "") + ".uasset"
        disk_path = os.path.join(content_dir, relative_path)

        if not os.path.exists(disk_path):
            package_path = bp_path.rsplit("/", 1)[0]
            asset_name = bp_path.rsplit("/", 1)[1]

            if not unreal.EditorAssetLibrary.does_directory_exist(package_path):
                unreal.EditorAssetLibrary.make_directory(package_path)

            try:
                parent_class = default_parent
                if cpp_class_path:
                    cls_name = cpp_class_path.split('.')[-1]
                    cpp_cls = getattr(unreal, cls_name, None)
                    if cpp_cls:
                        parent_class = cpp_cls

                factory = unreal.BlueprintFactory()
                factory.set_editor_property("parent_class", parent_class)

                bp = asset_tools.create_asset(asset_name, package_path, unreal.Blueprint, factory)
                if bp:
                    if asset_name == "BP_Player":
                        setup_bp_player_components(bp)

                    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
                    unreal.EditorAssetLibrary.save_loaded_asset(bp)
                    unreal.log(f"[Service:BP_Placeholder] Creado y configurado BP '{asset_name}' en 2D XY.")
            except Exception as e:
                unreal.log_error(f"[Service:BP_Placeholder] Error en {bp_path}: {e}")
