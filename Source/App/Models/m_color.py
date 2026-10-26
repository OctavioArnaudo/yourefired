# ============================================================
# YOU'RE FIRED - Model: Ultra-Vivid Theme & Object Color Palette
# ============================================================
import unreal

COLOR_PALETTE = {
    # Suelo y Paredes (Oficina moderna con contraste colorido)
    "Floor": unreal.LinearColor(0.05, 0.5, 0.85, 1.0),         # Azul Océano Vívido
    "Wall_North": unreal.LinearColor(0.95, 0.25, 0.5, 1.0),     # Rosa Magenta Vívido
    "Wall_South": unreal.LinearColor(0.95, 0.25, 0.5, 1.0),     # Rosa Magenta Vívido
    "Wall_East": unreal.LinearColor(0.2, 0.85, 0.4, 1.0),       # Verde Esmeralda Vívido
    "Wall_West": unreal.LinearColor(0.2, 0.85, 0.4, 1.0),       # Verde Esmeralda Vívido
    "Wall": unreal.LinearColor(0.95, 0.25, 0.5, 1.0),

    # Mobiliario de Oficina
    "Desk": unreal.LinearColor(0.85, 0.45, 0.05, 1.0),          # Naranja Ámbar Brillante
    "Chair": unreal.LinearColor(0.6, 0.1, 0.85, 1.0),           # Violeta Eléctrico

    # Personajes y Enemigos
    "Player": unreal.LinearColor(0.0, 0.85, 1.0, 1.0),          # Cyan Neón Vívido
    "Coworker": unreal.LinearColor(1.0, 0.1, 0.1, 1.0),         # Rojo Carmin Intenso
    "Supervisor": unreal.LinearColor(1.0, 0.5, 0.0, 1.0),       # Naranja Fuego Vívido

    # Objetos Interactivos
    "Coffee": unreal.LinearColor(0.9, 0.65, 0.1, 1.0),          # Café Dorado
    "Signature": unreal.LinearColor(1.0, 0.9, 0.0, 1.0),        # Amarillo Sol Vívido
    "Door": unreal.LinearColor(0.0, 0.95, 0.8, 1.0),            # Turquesa Neón

    # Interfaz de Usuario
    "UI_Backdrop": unreal.LinearColor(0.08, 0.25, 0.65, 1.0),   # Azul Real Vívido
    "UI_Button_Start": unreal.LinearColor(0.1, 0.95, 0.35, 1.0), # Verde Vivo
    "UI_Button_Settings": unreal.LinearColor(1.0, 0.85, 0.0, 1.0),# Amarillo Vivo
    "UI_Button_Quit": unreal.LinearColor(1.0, 0.2, 0.2, 1.0),      # Rojo Vivo
    "UI_Button_Volume": unreal.LinearColor(1.0, 0.85, 0.0, 1.0),
    "UI_Button_Back": unreal.LinearColor(1.0, 0.2, 0.2, 1.0),
    "UI_Button_Restart": unreal.LinearColor(0.1, 0.95, 0.35, 1.0),
    "UI_Button": unreal.LinearColor(0.0, 0.8, 1.0, 1.0),
    "UI": unreal.LinearColor(0.1, 0.7, 1.0, 1.0)
}

class MColorData:
    """Model: Definición de datos de color."""
    def __init__(self, value=100.0, is_active=True):
        self.value = value
        self.is_active = is_active
