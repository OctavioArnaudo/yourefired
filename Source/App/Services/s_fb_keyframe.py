# ============================================================
# YOU'RE FIRED - Service: Unitary PaperFlipbook KeyFrame Assembler
# ============================================================
import unreal

def build_flipbook_keyframes(sprites, frame_run=1):
    """Service: Construye el arreglo de PaperFlipbookKeyFrame a partir de una lista de PaperSprites."""
    keyframes = []
    for sprite in sprites:
        kf = unreal.PaperFlipbookKeyFrame()
        kf.set_editor_property("sprite", sprite)
        kf.set_editor_property("frame_run", frame_run)
        keyframes.append(kf)
    return keyframes
