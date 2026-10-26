import unreal
from .m_player import MPlayerData

class MWorkerCharacterData(MPlayerData):
    """Model data for Worker Character."""
    def __init__(self):
        super().__init__()
        self.b_is_working = True
        self.work_speed_multiplier = 1.0
