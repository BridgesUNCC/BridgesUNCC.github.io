import random
from bridges import *

class AudioTest(AudioClip):
    def remove_vocals(self) -> None:
        for i in range(self.sample_count):
            left = self.get_sample(0, i)
            right = self.get_sample(1, i)
            self.set_sample(0, i, (left - right) / 2.0)
            self.set_sample(1, i, (left - right) / 2.0)

    def fade_in(self, fade_length: int) -> None:
        for i in range(min(self.sample_count, fade_length)):
            for c in range(self.num_channels):
                self.set_sample(c, i, self.get_sample(c, i) * (i / float(fade_length)))

    def fade_out(self, fade_length: int) -> None:
        m = min(self.sample_count, fade_length)
        for i in range(self.sample_count - 1, self.sample_count - m, -1):
            for c in range(self.num_channels):
                self.set_sample(c, i, int(self.get_sample(c, i) * ((self.sample_count - i) / float(fade_length))))

    def fade(self, fade_length: int) -> None:
        self.fade_in(fade_length)
        self.fade_out(fade_length)

    def left_to_right(self, pan_length: int) -> None:
        for i in range(min(self.sample_count, pan_length)):
            self.set_sample(0, i, self.get_sample(0, i) * (1.0 - (i / float(pan_length))))
            self.set_sample(1, i, self.get_sample(1, i) * (i / float(pan_length)))

    def generate_sawtooth(self, period=500) -> None:
        for s in range(self.sample_count):
            for c in range(self.num_channels):
                ratio = (int(s) % int(period)) / float(period)
                ratio = (ratio - 0.5) / 0.5
                self.set_sample(c, s, ratio * ((2 ** 32 / 2.0) - 1.0))
                
    def generate_sine(self) -> None:
        for s in range(self.sample_count):
            for c in range(self.num_channels):
                val = math.sin(s / 20)
                self.set_sample(c, s, val * ((2 ** 32 / 2.0) - 1.0))

    def generate_square(self) -> None:
        for s in range(self.sample_count):
            for c in range(self.num_channels):
                val = math.sin(s / 20)
                if val >= 0:
                    val = 0 if val < 0.5 else 1
                else:
                    val = 0 if val > -0.5 else -1
                self.set_sample(c, s, val * ((2 ** 32 / 2.0) - 1.0))

def main():
    clip = AudioTest(sample_count=44100*5, num_channels=2)

    clip.generate_sine()

    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")
    bridges.connector.set_server("clone")
    bridges.set_data_structure(clip)

    clip.display()
    bridges.visualize()

if __name__ == "__main__":
    main()