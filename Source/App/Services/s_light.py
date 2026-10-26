# ============================================================
# YOU'RE FIRED - Service : Light
# ============================================================
import unreal

def process_light_service(data_model=None):
    """Service: Algoritmo de servicio y procesamiento lógico para Light."""
    unreal.log("[Service:Light] Procesando servicio especializado para Light.")
    if data_model:
        return data_model.is_active
    return True
