# ============================================================
# YOU'RE FIRED - Service: Primary Raw Asset Placeholder Generator (.png, .jpg, .fbx)
# ============================================================
import unreal
import os
import m_raw_placeholder

def ensure_raw_placeholders():
    """Service: Crea carpetas y archivos físicos .png/.fbx exclusivamente dentro de Content/YoureFired/RawAssets/."""
    unreal.log("[Service:RawPlaceholder] Verificando y generando estructura física en Content/YoureFired/RawAssets/...")

    raw_dir = m_raw_placeholder.RAW_DIR
    if not os.path.exists(raw_dir):
        os.makedirs(raw_dir, exist_ok=True)

    # 1. Generar placeholders para texturas .png
    for rel_path in m_raw_placeholder.EXPECTED_RAW_TEXTURES:
        full_path = os.path.join(raw_dir, rel_path)
        folder_path = os.path.dirname(full_path)
        if not os.path.exists(folder_path):
            os.makedirs(folder_path, exist_ok=True)

        if not os.path.exists(full_path):
            try:
                with open(full_path, "wb") as f:
                    png_1x1_bytes = b'\x89PNG\r\n\x1a\n\x00\x00\x00\rIHDR\x00\x00\x00\x01\x00\x00\x00\x01\x08\x06\x00\x00\x00\x1f\x15c4\x00\x00\x00\rIDATx\x9cc\xf8\xff\xff?\x03\x00\x05\xfe\x02\xfe\xa7\x35\x81\x84\x00\x00\x00\x00IEND\xaeB`\x82'
                    f.write(png_1x1_bytes)
                unreal.log(f"[Service:RawPlaceholder] [CREADO PLACEHOLDER PNG] Ubica tu sprite en: {full_path}")
            except Exception as e:
                unreal.log_error(f"[Service:RawPlaceholder] Error creando PNG '{full_path}': {e}")

    # 2. Generar placeholders para modelos .fbx
    for rel_path in m_raw_placeholder.EXPECTED_RAW_MESHES:
        full_path = os.path.join(raw_dir, rel_path)
        folder_path = os.path.dirname(full_path)
        if not os.path.exists(folder_path):
            os.makedirs(folder_path, exist_ok=True)

        if not os.path.exists(full_path):
            try:
                with open(full_path, "w", encoding="utf-8") as f:
                    f.write(f"; FBX Placeholder for {os.path.basename(full_path)}\n; Place your custom 3D model FBX file here.\n")
                unreal.log(f"[Service:RawPlaceholder] [CREADO PLACEHOLDER FBX] Ubica tu modelo 3D en: {full_path}")
            except Exception as e:
                unreal.log_error(f"[Service:RawPlaceholder] Error creando FBX '{full_path}': {e}")

    unreal.log(f"[Service:RawPlaceholder] === ESTRUCTURA DE SPRITES EN CONTENT LISTA EN '{raw_dir}' ===")
