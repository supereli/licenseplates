import sys
sys.path.append("packages")
import os
import requests
import json
import pytesseract
from PIL import Image
import urllib2
import ssl
import re

if hasattr(ssl, '_create_unverified_context'):
   ssl._create_default_https_context = ssl._create_unverified_context

def createPayloadDict():
   payload = os.getenv('PAYLOAD_FILE')
   payloadfile = open(payload)
   payloadstring = payloadfile.read()
   print(payloadstring)
   jsondict = json.loads(payloadstring)
   return jsondict

def printAndOcrImage(imageName,imageUrl):
    print('Image Name: ' + imageName)
    print('Image URL: ' + imageUrl)
    print('OCR on image: ')
    print(pytesseract.image_to_string(Image.open('./images/' + imageName)))

def downloadImage(imageName,imageUrl):
   imageget = urllib2.urlopen(imageUrl)
   with open('./images/' + imageName,'wb') as output:
      output.write(imageget.read())

print(os.getenv('PAYLOAD_FILE'))
payloaddict=createPayloadDict()
theImageUrl=payloaddict['imageUrl']
theImageName=re.findall("inbox\/(.*)\.",payloaddict['imageUrl'])[0]
print(theImageName)
print(theImageUrl)

downloadImage(theImageName,theImageUrl)
printAndOcrImage(theImageName,theImageUrl)

#payloaddict = createPayloadDict()
#imageName = payloaddict['IMAGE_NAME']
#imageUrl = payloaddict['IMAGE_URL']

#imageName='sacramento.jpg'
#imageUrl='https://www.cabinetreport.com/uploads/CALicensePlate.jpg'
#imageName='skydog.jpg'
#imageUrl='https://www.bluescentric.com/images/license-plates/10250/skydog-license-plate.png'
