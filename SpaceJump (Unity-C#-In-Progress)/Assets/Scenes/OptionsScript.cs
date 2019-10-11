using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Audio;

public class OptionsScript : MonoBehaviour
{
   // public AudioMixer audioMixer;

    //public void SetVolume (float volume)
 //  {
    //   audioMixer.SetFloat("volume", volume);
   //}

//set difficulty level function [easy, medium, hard] 
/*  
   public void setDifficulty()
   {

   }
   */

 private AudioSource AudioSrc;
 
 private float AudioVolume = 1f;
 
 void Start () {
  AudioSrc = GetComponent<AudioSource>();
 }
 
 void Update () {
  AudioSrc.volume = AudioVolume;
 }
 
 public void SetVolume(float vol)
 {
  AudioVolume = vol;
   //audioMixer.SetFloat("volume", vol);
 }

   
}
