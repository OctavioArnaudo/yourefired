# ============================================================
# YOU'RE FIRED - Service: Unified Primary Asset Placeholder Generator
# ============================================================
import unreal
import os
import m_raw_placeholder

def ensure_raw_placeholders():
    """Service: Genera archivos físicos .png, .jpg y .fbx en Content/YoureFired/ unificados por categoría (Textures/, Meshes/)."""
    unreal.log("[Service:RawPlaceholder] Verificando y generando archivos primarios en Content/YoureFired/...")

    base_dir = m_raw_placeholder.CONTENT_DIR

    # 1. Generar placeholders para texturas .png
    for rel_path in m_raw_placeholder.EXPECTED_RAW_TEXTURES:
        full_path = os.path.join(base_dir, rel_path)
        folder_path = os.path.dirname(full_path)
        if not os.path.exists(folder_path):
            os.makedirs(folder_path, exist_ok=True)

        if not os.path.exists(full_path):
            try:
                with open(full_path, "wb") as f:
                    png_1x1_bytes = b'\x89PNG\r\n\x1a\n\x00\x00\x00\rIHDR\x00\x00\x00\x01\x00\x00\x00\x01\x08\x06\x00\x00\x00\x1f\x15c4\x00\x00\x00\rIDATx\x9cc\xf8\xff\xff?\x03\x00\x05\xfe\x02\xfe\xa7\x35\x81\x84\x00\x00\x00\x00IEND\xaeB`\x82'
                    f.write(png_1x1_bytes)
                unreal.log(f"[Service:RawPlaceholder] [CREADO PNG UNIFICADO] {full_path}")
            except Exception as e:
                unreal.log_error(f"[Service:RawPlaceholder] Error creando PNG '{full_path}': {e}")

    # 2. Generar placeholders para modelos .fbx
    for rel_path in m_raw_placeholder.EXPECTED_RAW_MESHES:
        full_path = os.path.join(base_dir, rel_path)
        folder_path = os.path.dirname(full_path)
        if not os.path.exists(folder_path):
            os.makedirs(folder_path, exist_ok=True)

        if not os.path.exists(full_path):
            try:
                with open(full_path, "w", encoding="utf-8") as f:
                    f.write(f"; FBX Placeholder for {os.path.basename(full_path)}\n")
                unreal.log(f"[Service:RawPlaceholder] [CREADO FBX UNIFICADO] {full_path}")
            except Exception as e:
                unreal.log_error(f"[Service:RawPlaceholder] Error creando FBX '{full_path}': {e}")
