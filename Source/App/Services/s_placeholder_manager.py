# ============================================================
# YOU'RE FIRED - Service: Asset Placeholder Manager
# ============================================================
import unreal
import os

def ensure_asset_placeholders():
    """Service: Verifica y genera físicamente los archivos .uasset en disco para cada malla y material del juego."""
    unreal.log("[Service:PlaceholderManager] Verificando archivos .uasset físicos en disco (Content/YoureFired/)...")

    placeholders = [
        # Materiales
        ("/Game/YoureFired/Materials/M_OfficeStyle.M_OfficeStyle", "/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"),
        ("/Game/YoureFired/Materials/M_UITheme.M_UITheme", "/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"),

        # Geometría base y entorno
        ("/Game/YoureFired/Meshes/Floor_Main.Floor_Main", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/Wall_North.Wall_North", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/Wall_South.Wall_South", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/Wall_East.Wall_East", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/Wall_West.Wall_West", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/Cubicle_Desk.Cubicle_Desk", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/Cubicle_Chair.Cubicle_Chair", "/Engine/BasicShapes/Cylinder.Cylinder"),

        # Personajes y Enemigos
        ("/Game/YoureFired/Meshes/Player.Player", "/Engine/BasicShapes/Sphere.Sphere"),
        ("/Game/YoureFired/Meshes/CoworkerEnemy.CoworkerEnemy", "/Engine/BasicShapes/Cylinder.Cylinder"),
        ("/Game/YoureFired/Meshes/SupervisorEnemy.SupervisorEnemy", "/Engine/BasicShapes/Cone.Cone"),

        # Pickups e Ítems
        ("/Game/YoureFired/Meshes/CoffeeItem.CoffeeItem", "/Engine/BasicShapes/Cylinder.Cylinder"),
        ("/Game/YoureFired/Meshes/SignatureItem.SignatureItem", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/OfficeDoor.OfficeDoor", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/WeaponBase.WeaponBase", "/Engine/BasicShapes/Cone.Cone")
    ]

    content_dir = unreal.Paths.project_content_dir()

    for custom_path, source_base in placeholders:
        # Calcular ruta física en disco (.uasset)
        relative_path = custom_path.replace("/Game/", "").split(".")[0] + ".uasset"
        disk_path = os.path.join(content_dir, relative_path)

        if not os.path.exists(disk_path):
            parts = custom_path.split(".")
            object_path = parts[0]
            package_path = object_path.rsplit("/", 1)[0]

            if not unreal.EditorAssetLibrary.does_directory_exist(package_path):
                unreal.EditorAssetLibrary.make_directory(package_path)

            try:
                success = unreal.EditorAssetLibrary.duplicate_asset(source_base, object_path)
                if success:
                    new_asset = unreal.EditorAssetLibrary.load_asset(custom_path)
                    if new_asset:
                        unreal.EditorAssetLibrary.save_loaded_asset(new_asset)
                    unreal.log(f"[Service:PlaceholderManager] [CREADO EN DISCO] Archivo .uasset generado: {disk_path}")
                else:
                    unreal.log_error(f"[Service:PlaceholderManager] Falló duplicate_asset para {custom_path}")
            except Exception as e:
                unreal.log_error(f"[Service:PlaceholderManager] Excepción al crear {custom_path}: {str(e)}")
        else:
            unreal.log(f"[Service:PlaceholderManager] [EXISTE EN DISCO] {disk_path}")

    unreal.log("[Service:PlaceholderManager] === VERIFICACION FISICA COMPLETADA ===")
