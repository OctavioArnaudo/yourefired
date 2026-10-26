# ============================================================
# YOU'RE FIRED - Service : OfficePerimeter
# ============================================================
import unreal

def process_office_perimeter_service(data_model=None):
    """Service: Algoritmo de servicio y procesamiento lógico para OfficePerimeter."""
    unreal.log("[Service:OfficePerimeter] Procesando servicio especializado para OfficePerimeter.")
    if data_model:
        return data_model.is_active
    return True
