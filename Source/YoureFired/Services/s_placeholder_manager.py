import unreal

def ensure_asset_placeholders():
    """Service: Responsable exclusivo de generar placeholders físicos (.uasset) en disco si no existen."""
    unreal.log("[Service:PlaceholderManager] Verificando placeholders de assets en Content/YoureFired/...")

    placeholders = [
        ("/Game/YoureFired/Materials/M_OfficeStyle.M_OfficeStyle", "/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"),
        ("/Game/YoureFired/Meshes/Floor_Main.Floor_Main", "/Engine/BasicShapes/Cube.Cube")
    ]

    for custom_path, source_base in placeholders:
        if not unreal.EditorAssetLibrary.does_asset_exist(custom_path):
            parts = custom_path.split(".")
            object_path = parts[0]
            package_path = object_path.rsplit("/", 1)[0]

            if not unreal.EditorAssetLibrary.does_directory_exist(package_path):
                unreal.EditorAssetLibrary.make_directory(package_path)

            try:
                success = unreal.EditorAssetLibrary.duplicate_asset(source_base, object_path)
                if success:
                    unreal.log(f"[Service:PlaceholderManager] [CREADO] Placeholder .uasset generado en: {custom_path}")
            except Exception as e:
                unreal.log_error(f"[Service:PlaceholderManager] Error al crear placeholder {custom_path}: {str(e)}")
        else:
            unreal.log(f"[Service:PlaceholderManager] [EXISTENTE] Usando asset personalizado: {custom_path}")
