# ============================================================
# YOU'RE FIRED - Service: Primary Raw Asset Placeholder Generator (.png, .jpg, .fbx)
# ============================================================
import unreal
import os
import zlib
import struct
import m_raw_placeholder

def generate_valid_png_bytes(width=16, height=16, color=(255, 0, 128, 255)):
    """Genera bytes binarios de una imagen PNG válida de 16x16 con formato RGBA."""
    r, g, b, a = color
    png_signature = b'\x89PNG\r\n\x1a\n'

    ihdr_data = struct.pack(">IIBBBBB", width, height, 8, 6, 0, 0, 0)
    ihdr_crc = struct.pack(">I", zlib.crc32(b"IHDR" + ihdr_data) & 0xffffffff)
    ihdr_chunk = struct.pack(">I", len(ihdr_data)) + b"IHDR" + ihdr_data + ihdr_crc

    raw_data = bytearray()
    for y in range(height):
        raw_data.append(0)
        for x in range(width):
            raw_data.extend([r, g, b, a])

    compressed = zlib.compress(bytes(raw_data))
    idat_crc = struct.pack(">I", zlib.crc32(b"IDAT" + compressed) & 0xffffffff)
    idat_chunk = struct.pack(">I", len(compressed)) + b"IDAT" + compressed + idat_crc

    iend_crc = struct.pack(">I", zlib.crc32(b"IEND") & 0xffffffff)
    iend_chunk = struct.pack(">I", 0) + b"IEND" + iend_crc

    return png_signature + ihdr_chunk + idat_chunk + iend_chunk

def ensure_raw_placeholders():
    """Service: Genera archivos PNG 16x16 binarios válidos en Content/YoureFired/ unificados por categoría."""
    unreal.log("[Service:RawPlaceholder] Verificando e importando archivos primarios en Content/YoureFired/...")

    base_dir = m_raw_placeholder.CONTENT_DIR

    # 1. Generar placeholders PNG válidos
    valid_png_data = generate_valid_png_bytes(16, 16, (0, 180, 255, 255))
    for rel_path in m_raw_placeholder.EXPECTED_RAW_TEXTURES:
        full_path = os.path.join(base_dir, rel_path)
        folder_path = os.path.dirname(full_path)
        if not os.path.exists(folder_path):
            os.makedirs(folder_path, exist_ok=True)

        # Si no existe o tiene tamaño < 50 bytes (texto no válido), sobreescribir con PNG binario válido
        if not os.path.exists(full_path) or os.path.getsize(full_path) < 50:
            try:
                with open(full_path, "wb") as f:
                    f.write(valid_png_data)
                unreal.log(f"[Service:RawPlaceholder] [CREADO PNG 16x16 VALIDO] {full_path}")
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
