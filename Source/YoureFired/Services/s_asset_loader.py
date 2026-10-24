import unreal

def get_asset_with_fallback(custom_path, default_path):
    """
    Verifica si el asset propio existe en custom_path.
    - Si existe: Lo utiliza.
    - Si no existe: Genera automáticamente un archivo asset (placeholder .uasset) en esa ruta
      para que el usuario sepa exactamente qué archivo reemplazar, y usa el default como fallback.
    """
    if unreal.EditorAssetLibrary.does_asset_exist(custom_path):
        loaded_asset = unreal.EditorAssetLibrary.load_asset(custom_path)
        if loaded_asset:
            unreal.log(f"[AssetLoader] Usando asset personalizado existente: {custom_path}")
            return loaded_asset

    # Parsear ruta del paquete y nombre del asset (ej: /Game/YoureFired/Materials/M_OfficeStyle)
    parts = custom_path.split(".")
    object_path = parts[0]
    path_tokens = object_path.rsplit("/", 1)
    if len(path_tokens) == 2:
        package_path = path_tokens[0]
        asset_name = path_tokens[1]

        asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
        if asset_tools:
            try:
                # Determinar tipo de asset basado en el nombre o ruta
                if "Materials" in package_path:
                    factory = unreal.MaterialFactoryNew()
                    created_asset = asset_tools.create_asset(asset_name, package_path, unreal.Material, factory)
                    if created_asset:
                        unreal.log(f"[AssetLoader] [PLACEHOLDER CREADO] Material placeholder generado en: {custom_path}. Reemplázalo con tu asset.")
                elif "Meshes" in package_path:
                    factory = unreal.StaticMeshFactoryNew()
                    created_asset = asset_tools.create_asset(asset_name, package_path, unreal.StaticMesh, factory)
                    if created_asset:
                        unreal.log(f"[AssetLoader] [PLACEHOLDER CREADO] StaticMesh placeholder generado en: {custom_path}. Reemplázalo con tu asset.")
            except Exception as e:
                unreal.log_warning(f"[AssetLoader] No se pudo crear placeholder asset automático para {custom_path}: {str(e)}")

    unreal.log(f"[AssetLoader] Usando asset por defecto (hardcodeado) para: {custom_path} -> Fallback: {default_path}")
    return unreal.EditorAssetLibrary.load_asset(default_path)
