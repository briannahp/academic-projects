using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlatformGenerator : MonoBehaviour
{

    public GameObject thePlatform;
    //public GameObject[] thePlatforms;
    public Transform generationPoint;
    public float distanceBetween;
    public float minPlatformDistance;
    public float maxPlatformDistance;


    private float platformWidth;
    private int platformChoice;
    private float[] platformWidths;

    public ObjectPooler[] pooledObjects;


    //public ObjectPooler myPooledObject;

    // Start is called before the first frame update
    void Start()
    {
        int i = 0;
        //platformWidth = thePlatform.GetComponent<BoxCollider2D>().size.x;
        platformWidths = new float[pooledObjects.Length];

        while(i < pooledObjects.Length)
        {
            // Get box collider 
            platformWidths[i] = pooledObjects[i].theObject.GetComponent<BoxCollider2D>().size.x;
            i++;
        }

    }

    // Update is called once per frame
    void Update()
    {
        // if x position of object is less than the generation point
        if(transform.position.x < generationPoint.position.x)
        {
            // Randomly chooses a platform distance
            distanceBetween = Random.Range(minPlatformDistance, maxPlatformDistance);

            // Randomly chooses a platform size
            platformChoice = Random.Range(0, pooledObjects.Length);

            transform.position = new Vector3(transform.position.x + (platformWidths[platformChoice] / 2) + distanceBetween, transform.position.y, transform.position.z);


            // Activate a platform from the pooled object list and position it
            //Instantiate(thePlatforms[platformChoice], transform.position, transform.rotation);
            GameObject generatedPlatform = pooledObjects[platformChoice].GetPObject();
            generatedPlatform.transform.position = transform.position;
            generatedPlatform.transform.rotation = transform.rotation;
            generatedPlatform.SetActive(true);


            transform.position = new Vector3(transform.position.x + (platformWidths[platformChoice] / 2), transform.position.y, transform.position.z);
        }
        
    }
}
