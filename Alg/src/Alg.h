#include "AthenaBaseComps/AthHistogramAlgorithm.h"
#include "GeneratorObjects/McEventCollection.h"
#include "TrackerSimEvent/FaserSiHitCollection.h"
#include <TH1.h>

class Alg : public AthHistogramAlgorithm
{
    public:
    Alg(const std::string& name, ISvcLocator* pSvcLocator);

    virtual ~Alg();

    StatusCode initialize();
    StatusCode execute();
    StatusCode finalize();

    private:
    TH1* m_hist;
    SG::ReadHandleKey<McEventCollection> m_mcEventKey { this, "McEventCollection", "GEN_EVENT" };
    SG::ReadHandleKey<FaserSiHitCollection> m_faserSiHitCol { this, "FaserSiHitCollection", "SCT_Hits" };
};