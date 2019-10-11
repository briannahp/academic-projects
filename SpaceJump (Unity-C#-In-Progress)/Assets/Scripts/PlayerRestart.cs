using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerRestart : MonoBehaviour
{
    public Transform platformCreator;
    public PlayerController thePlayer;

    private Vector3 platformBegin;
    private Vector3 playerBegin;
    
    // Start is called before the first frame update
    void Start()
    {
        platformBegin = platformCreator.position;
        playerBegin = thePlayer.transform.position;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
