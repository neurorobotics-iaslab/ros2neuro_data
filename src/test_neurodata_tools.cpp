#include "ros2neuro_data/NeuroData.hpp"
#include "ros2neuro_data/NeuroDataTools.hpp"
#include "ros2neuro_msgs/msg/neuro_data_float.hpp"
#include "ros2neuro_msgs/msg/neuro_data_int32.hpp"

using namespace ros2neuro;

int main(int argc, char** argv) {

    size_t ns    = 32;
    size_t neeg  = 16;
    size_t ntri  = 1;

    NeuroDataInfo *ieeg, *itri;
    ros2neuro_msgs::msg::NeuroDataFloat    mfloat;
    ros2neuro_msgs::msg::NeuroDataInt32    mint32;

    NeuroData<float>    eeg(ns, neeg, "EEG");
    NeuroData<int32_t>    tri(ns, ntri, "TRI");

    ieeg = eeg.info();
    itri = tri.info();

    // Info eeg
    ieeg->unit = "[uV]";
    ieeg->transducter = "Active";
    ieeg->prefiltering = "Notch 50Hz | Highpass: 0.1 Hz";
    ieeg->minmax = {-823000.0, 823000.0};
    ieeg->isint  = 0;
    ieeg->labels = {"Fz", "FC3", "FC1", "FCz", "FC2", "FC4", "C3", "C1", 
                    "Cz", "C2", "C4", "CP3", "CP1", "CPz", "CP2", "CP4"};
    
    // Info trigger
    itri->unit = "[V]";
    itri->transducter = "Active";
    itri->prefiltering = "None";
    itri->minmax = {-10.0, 10.0};
    itri->isint  = 1;
    itri->labels = {"Status"};

    eeg.dump();
    tri.dump();


    // Genereting some data
    int32_t tritmp[tri.size()];
    float eegtmp[eeg.size()];
    for(auto i=0; i<tri.size(); i++)
        tritmp[i] = i+1;
    memcpy(tri.data(), tritmp, tri.size()*sizeof(int32_t));
    
    for(auto i=0; i<eeg.size(); i++)
        eegtmp[i] = i+1;
    memcpy(eeg.data(), eegtmp, eeg.size()*sizeof(float));
    
    // Convert to message
    NeuroDataTools::FromNeuroData(eeg, mfloat);
    NeuroDataTools::FromNeuroData(tri, mint32);

    printf("EEG message data:\n");
    for(auto it = mfloat.data.begin(); it != mfloat.data.end(); ++it)
        printf("%f ", (*it));
    printf("\n\n");

    printf("TRI message data:\n");
    for(auto it = mint32.data.begin(); it != mint32.data.end(); ++it)
        printf("%d ", (*it));
    printf("\n");

    return 0;
}
