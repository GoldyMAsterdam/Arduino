<?php
header('Access-Control-Allow-Origin: *');

// Wachtwoord
$password = "duurzaamhuisBO"; 

$json = file_get_contents('php://input');

if(empty($json)) {
  $json = file_get_contents("jsonInput.txt");
  echo $json;
}
else {
  if(strlen($json) > 1024) {
    exit("not parsing data, data is over 1024 characters!");
  }

  $data = json_decode($json);
  
  if(!isset($data->password) || $data->password !== $password) {
    exit("Toegang geweigerd: onjuist wachtwoord");
  }
  
  $fileContents = file_get_contents("jsonInput.txt");
  $fileData = json_decode($fileContents);

  $fileData->ldr = $data->ldr;
  $fileData->dht11->Temperature = $data->dht11->Temperature;
  $fileData->dht11->Humidity = $data->dht11->Humidity;
  $fileData->dht11->HeatIndex = $data->dht11->HeatIndex;

  $fileData->lights[0] = ($data->ldr < 300) ? true : false;
  
  $fileData->lights[1] = ($data->ldr >= 300 && $data->ldr < 600) ? true : false;
  
  $fileData->lights[2] = ($data->dht11->Temperature > 20) ? true : false;
  
  $finalJson = json_encode($fileData);

  $jsonFile = fopen("jsonInput.txt", "w");
  fwrite($jsonFile, $finalJson . "\n");
  fclose($jsonFile);

  header('Content-Type: application/json; charset-utf-8');
  echo json_encode($finalJson);
}
?>