# -*- coding: utf-8 -*-
# Instituto de Física - Universidade Federal de Alagoas
# Grupo de Desenvolvimento de Experimento de Ensino de Física
# Técnico de Laboratório / Física
# Data: novembro de 2019

from threading import Thread
import cv2
import wx
import controle

# defines
WIDTH = 900
HIGH = 600


def debug(value=''):
    DEBUG = True
    if DEBUG:
        print(value)


class Camera(Thread):
    def __init__(self):
        Thread.__init__(self)
        try:
            self.__captura = cv2.VideoCapture(0)
            self._stop = False
        except:
            debug('Nenhuma webcam conectada.')
            self._stop = True
        
    def stop(self):
        self._stop = True
     
    def run(self):
        try:
            while not self._stop:
                ret, frame = self.__captura.read()
                cv2.imshow("Video", frame)
                k = cv2.waitKey(30) & 0xff
                if k == 27: # escape button
                    break
        except:
            debug('Nenhuma webcam conectada.')
        self.__captura.release()
        cv2.destroyAllWindows()


class Interface:
    @staticmethod
    def create_box(args, _type):
        box = wx.BoxSizer(_type)
        for item in args:
            box.Add(item, 0, wx.ALL|wx.CENTER, 5)
        return box
        
    def __init__(self, title="Controladora Carga/Descarga Capacitor"):
        # funções lambdas
        hbox = lambda args: Interface.create_box(args, wx.HORIZONTAL)
        vbox = lambda args: Interface.create_box(args, wx.VERTICAL)
        statictext = lambda text, s=(150,15): wx.StaticText(panel,label=text, size=s)
        button = lambda text: wx.Button(panel, -1, text, size=(170, 25))
        
        # configuração inicial
        self.app = wx.App()
        window = wx.Frame(None, title=title, size=(WIDTH,HIGH))
        panel = wx.Panel(window)

        # Construção da interface
        lbl_descript = statictext("Tempo de carga/descarga = ", (40,15))
        self.tempo = wx.SpinCtrl(panel, initial=10, size=(50,25))
        lbl_unity = statictext('(segundos)')
        hbox_1 = hbox( [lbl_descript, self.tempo, lbl_unity] )
        
        self.carregar = button("Carregar capacitor")
        self.descarregar = button("Descarregar capacitor")
        
        self.carregar.Bind(wx.EVT_BUTTON, lambda event: controle.fase_carga(event, int(self.tempo.GetValue() ) ) )
        self.descarregar.Bind(wx.EVT_BUTTON, lambda event: controle.fase_descarga(event, int(self.tempo.GetValue() ) ) )
        
        vbox_1 = vbox([hbox_1, self.carregar, self.descarregar])
        
        total_box = hbox([vbox_1])

        panel.SetSizer(total_box)
        #self.videopanel = wx.Panel(window)
        #sizer = hbox([panel, self.videopanel])
        #window.SetSizer(sizer)
        window.Centre()
        window.Show(True)
        self.app.MainLoop()

def main():
    #camera = Camera()
    #camera.start()
    inter = Interface()
    inter.app.MainLoop()
    
    #camera.stop()

if __name__ == '__main__':
    main()
